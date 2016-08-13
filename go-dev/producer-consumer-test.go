package main

import (
	"fmt"
	//"time"
)

func Producer(queue chan<- int) {
	for i := 0; i < 10; i++ {
		fmt.Println("send: ", i)
		queue <- i
	}
}
func Consumer(queue <-chan int) {
	for i := 0; i < 10; i++ {
		v := <-queue
		fmt.Println("receive:", v)
	}
}
func main() {
	queue := make(chan int, 0)
	go Producer(queue)

	Consumer(queue)

	//time.Sleep(1e9) //让Producer与Consumer完成
}
