package main

import (
	"log"
	"net"
    "time"
    "encoding/binary"
    "message"
    //"ucloud.pb"
    "ucloud_uaccount.pb"
    "github.com/golang/protobuf/proto"
)

func main() {
	log.Println("begin dial...")
	conn, err := net.Dial("tcp", "172.23.0.178:20142")
	if err != nil {
		log.Println("dial error:", err)
		return
	}
	defer conn.Close()
	log.Println("dial ok")

    var flow uint32 = 1
    var session string = "1234-5678-abcd"
    var messageType int32 = ucloud_uaccount.MessageType_value["GET_USER_INFO_NEW_REQUEST"]
    var workerIndex int32 = 0
    var tintFlag bool = false
    var sourceEntity uint32 = 1234
    var destEntity uint32 = 4321
    var callPurpose string = "uaccount-test"
    var accessToken string = ""
    var reserved string = ""
    msg, err := message.NewMessage_v2(flow, session, messageType, workerIndex, tintFlag, sourceEntity, destEntity, callPurpose, accessToken, reserved)
    if err != nil {
        log.Println("make msg error",  err)
        return
    }
    request := new(ucloud_uaccount.GetUserInfoNewRequest)
    request.UserEmail = []string{"vitas.liu@99bill.com"}
    err = proto.SetExtension(msg.Body, ucloud_uaccount.E_GetUserInfoNewRequest, request)
    buffer, _ := proto.Marshal(msg)

    var head_buf = make([]byte, 4)
    log.Printf("msg len %d\n", len(buffer))
    binary.BigEndian.PutUint32(head_buf[:4], uint32(len(buffer)))
    conn.Write(head_buf[:4])
    conn.Write(buffer)
    for {
        time.Sleep(2 * time.Second)
        var buf = make([]byte, 1024)
        var n int
        n, err = conn.Read(buf)
        if err != nil {
            log.Printf("conn read %d bytes,  error: %s", n, err)
            return
        }
        log.Printf("read %d bytes, content is %s\n", n, string(buf[:n]))
    }
}
