package main

import (
	"fmt"
	//"net"
	"net/http"
	"net/url"
	"strings"
)

func main() {
	fmt.Printf("%q\n", strings.Split(".cn-bj.ufileos.com", ","))
	var host string = "http://www.ufile.ucloud.cn:8888"
	/*
			u, err := url.Parse(host)
			if err != nil {
				fmt.Printf("err:%v\n", err)
				return
			}
			fmt.Printf("url:%v\n", u)
		host, port, _ := net.SplitHostPort(host)
		fmt.Println(host)
		fmt.Println(port)
	*/

	if strings.Index(host, "http://") == 0 {
		host = host[7:len(host)]
	}
	//fmt.Println("host", host)

	key := "example.txt"
	uri := url.URL{
		Scheme: "http",
		Host:   host,
		Path:   "/" + key,
	}

	putReq, err := http.NewRequest("PUT", uri.String(), nil)
	if err != nil {
		fmt.Printf("err:%v\n", err)
	}
	fmt.Printf("req:%v\n", putReq)
}
