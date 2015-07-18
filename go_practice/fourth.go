// You can edit this code!
// Click here and start typing.
package main

import "fmt"
import "time"

func main() {
	hello()

	str("string")
	str("あいう")

	go co1()
	go co2()

	time.Sleep(50 * time.Second);
}

func hello() {
	fmt.Println("Hello, 世界")
}

func str(x string) {
	fmt.Println("string = |", x, "|, len = ", len(x));
}

func co1() {
	for i := 0; i < 100; i++ {
		fmt.Println("  co1 : ", i)
		time.Sleep(1 * time.Second);
	}
}

func co2() {
	for i := 0; i < 100; i++ {
		fmt.Println("    co2 : ", i)
		time.Sleep(1 * time.Second);
	}
}


