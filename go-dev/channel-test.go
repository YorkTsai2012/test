package main

import (
	"fmt"
	"time"
)

var ch chan int

//必须有一个定长队列
func Producer() {
	for count := 0; count < 1000; count++ {
		fmt.Printf("task <- %v\n", count)
		ch <- count
		time.Sleep(2 * time.Second)
	}
}

func Consumer(cid uint32, Q chan uint32) {
	//defer (Q <- cid)
	fmt.Printf("cid: %d, task: %v\n", cid, <-ch)
	time.Sleep(3 * time.Second)
	Q <- cid
}

func ConsumerSched() {
	var max int = 5
	Q := make(chan uint32, max)
	for i := 0; i < max; i++ {
		Q <- uint32(100 + i)
	}
	for {
		go Consumer(<-Q, Q)
	}
}

func main() {
	ch = make(chan int, 2)
	//限定consumer的个数
	go ConsumerSched()
	Producer()
}
