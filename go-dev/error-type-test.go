/*
type error interface {
    Error() string
}

与 fmt.Stringer 类似， error 类型是一个内建接口，并`fmt` 包在输出时也会试图匹配 `error`
*/

package main

import (
	"errors"
	"fmt"
	"math"
)

type ErrNegativeSqrt float64

// 实现了error接口 就可以匹配error类型
func (e ErrNegativeSqrt) Error() string {
	return fmt.Sprintf("cannot Sqrt negative number: %v", float64(e))
}

func Sqrt(x float64) (float64, error) {
	if x < 0 {
		return x, ErrNegativeSqrt(x)
	}
	return math.Sqrt(x), nil
}

var (
	ErrHoldOnOplog = errors.New("Hold on oplog")
)

func main() {
	fmt.Println(Sqrt(0))
	fmt.Println(Sqrt(-2))
	fmt.Printf("%v\n", errors.New("Fucking Error"))
	var err1 error = ErrHoldOnOplog
	var err2 error = ErrHoldOnOplog
	if err1 == err2 {
		fmt.Println("the same error")
	}
}
