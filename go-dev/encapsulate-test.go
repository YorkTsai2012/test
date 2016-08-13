package main

import "fmt"

type data struct {
	val int
}

//只有在你需要修改对象的时候，才必须用指针。它不是Go语言的约束，而是一种自然约束。
//究其原因，是因为Go和C语言一样，类型都是基于值传递。要想修改变量的值，只能传递指针。
func (p_data *data) set(num int) {
	p_data.val = num
}
func (p_data *data) show() {
	fmt.Println(p_data.val)
}
func main() {
//	p_data := &data{4}
    var p_data data
	p_data.set(5)
	p_data.show()
    p_data.val = 4
	p_data.show()
}
