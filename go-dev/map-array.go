package main

import (
	"fmt"
)

func main() {
	DomainIps := make(map[string][]string)

	DomainIps["cn-bj.ufileos.com:9090"] = append(DomainIps["cn-bj.ufileos.com:9090"], "192.168.152.14")

	fmt.Println(DomainIps)
}
