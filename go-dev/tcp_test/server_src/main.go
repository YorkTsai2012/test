package main

import (
    "fmt"
    "net"
    "os"
    "time"
)

func main() {
    service := "127.0.0.1:7777"
    tcpAddr, err := net.ResolveTCPAddr("tcp4", service)
    checkError(err)
    listener, err := net.ListenTCP("tcp", tcpAddr)
    checkError(err)
    for {
        conn, err := listener.AcceptTCP()
        if err != nil {
            continue
        }
        go handleConnection(conn)
    }
}

func handleConnection(conn *net.TCPConn) {
    defer conn.Close()                // we're finished with this client
    var reader io.Reader
    n, err := conn.ReadFrom(reader)
    var buffer [1024]byte
    while(reader.read(buffer) != 0) {
        fmt.Println("%s", buffer)
    }
    daytime := time.Now().String()
    fmt.Println("daytime:", daytime)
    conn.Write([]byte(daytime)) // don't care about return value
}

func checkError(err error) {
    if err != nil {
        fmt.Fprintf(os.Stderr, "Fatal error: %s\n", err.Error())
        os.Exit(1)
    }
}
