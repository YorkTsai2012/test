package main

import (
	"fmt"
	"net"
	"net/http"
	"net/url"
	"strings"
)

func main() {
	fmt.Printf("%q\n", strings.Split(".cn-bj.ufileos.com", ","))
	var url_str string = "http://www.ufile.ucloud.cn:8888"
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
	/*
		if host[:7] == "http://" {
			host = host[7:len(host)]
		}
	*/
	_url, _ := url.Parse(url_str)
	host := _url.String()
	fmt.Println("host", host)
	if host[:7] == "http://" {
		host = host[7:len(host)]
	}
	fmt.Println("host", host)

	host, port, _ := net.SplitHostPort(host)
	fmt.Println("host", host)
	fmt.Println("port", port)

	key := "example.txt"
	uri := url.URL{
		Scheme: "http",
		Host:   host + ":" + port,
		Path:   "/" + key,
	}

	putReq, err := http.NewRequest("PUT", uri.String(), nil)
	if err != nil {
		fmt.Printf("err:%v\n", err)
	}
	putReq.Host = host
	fmt.Printf("req:%v\n", putReq)
}
