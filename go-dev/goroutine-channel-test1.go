
//ref http://studygolang.com/articles/2792

package main

import "strconv"
import "fmt"

func main() {
    //在主goroutine中要先有读取chan的请求，之后才可以赋值，即有需求才会有chan赋值的举动，否则先别碰chan，不然会死锁
    //1
    taskChan := make(chan string, 3)
    doneChan := make(chan int, 1)

    for i := 0; i < 3; i++ {
        taskChan <- strconv.Itoa(i)
        fmt.Println("send: ", i)
    }

    go func() {
        for i := 0; i < 3; i++ {
            task := <-taskChan
            fmt.Println("received: ", task)
        }
        doneChan <- 1
    }()
    <-doneChan

    fmt.Println("stage 1 over")
    // 2和3是一对，只是把给chan的赋值或是读值调换了
    //2
    ch2 := make(chan int)
    //ch2 <- 1 如果在这先给ch2赋值，那么就会阻塞，因为不知道有谁在用这个ch2.
    go func() {
        stage2value := <-ch2
        fmt.Printf("chan 2 received, ch2=%d\n", stage2value)
    }()
    ch2 <- 200    //放置在这儿刚好了
    fmt.Println("stage 2 over")

    //3
    ch3 := make(chan int)
    go func() {
        ch3 <- 300
        fmt.Println("chan 3 received")
    }()
    stage3value := <-ch3    //这是告诉主goroutine有一个叫ch3的chan需要等待，等到ch3完成后，就可以继续往下走了
    fmt.Printf("stage 3 over, ch3=%d\n", stage3value)

    //3
     //带缓存的chan，需要把缓存装满后才能继续后续
    c2 := make(chan int, 2)
    //写数据位置1  此处赋值会死锁
    go func() {
        fmt.Println("before 2 received")
        r := <-c2
        fmt.Printf("after 2 received, value=%d\n", r)
    }()
    //写数据位置2 此处是正确位置
    c2 <- 1 //被接收
    c2 <- 3  // 管道还能塞两个数据
    c2 <- 2
    //阻塞c2 <- 4 //不能再塞了

    fmt.Println("end")
}
