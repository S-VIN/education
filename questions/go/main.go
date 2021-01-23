package main

import "fmt"

func main(){
    var a int
    fmt.Scan(&a)
	a = a * 2
	var b int = a
	b = b / 60
	a = a % 60
	fmt.Print("It is ", b," hours ", a, " minutes.")
}