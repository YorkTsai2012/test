package main

import "fmt"
import "strconv"

type IPAddr [4]byte

// TODO: Add a "String() string" method to IPAddr.

func (ip IPAddr) String() string {
	return fmt.Sprintf("%v", ip[0]) +
		"." + strconv.Itoa(int(ip[1])) +
		"." + strconv.Itoa(int(ip[2])) +
		"." + strconv.Itoa(int(ip[3]))

}

func main() {
	addrs := map[string]IPAddr{
		"loopback":  {127, 0, 0, 1},
		"googleDNS": {8, 8, 8, 8},
	}
	for n, a := range addrs {
		fmt.Printf("%v: %v\n", n, a)
	}
}
