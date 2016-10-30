package main

import (
	"fmt"
)

func main() {

	var full chan int = make(chan int, 100)
	/*
		var done chan bool = make(chan bool)
		go func() {
			for {
				for i := 0; i < 100; i++ {
					x := <-full
					fmt.Println("receive:", x)
				}
			}
			done <- true
		}()

		go func() {
			for {
				for i := 0; i < 50; i++ {
					full <- i
					fmt.Println("send:", i)
				}
			}
		}()
		<-done
	*/
	for i := 0; i < 100; i++ {
		full <- i
		fmt.Println("send:", i)
	}
	for {
		fmt.Println("wait")

	}
	//close(full)
}
