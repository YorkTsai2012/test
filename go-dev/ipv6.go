package main

import (
    "fmt"
	"net"
)

func main() {

    var src string  = "2003:da8:2004:1000:0a09:5292:0100:3797"
    fmt.Printf("src: %s\n", src)
    ip := net.ParseIP(src)
    fmt.Printf("dst: %s\n", ip.String())
}
