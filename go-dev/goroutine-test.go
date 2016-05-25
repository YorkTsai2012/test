
package main

import (
    "fmt"
    "time"
)

func say(s string) {
    for i := 0; i < 5; i++ {
        //time.Sleep(100 * time.Millisecond)
        fmt.Println(s)
    }
}

func main() {
    go say("world")
    say("hello")//主线程退出,goroutine可能没有机会执行
    time.Sleep(1000 * time.Millisecond)
}


