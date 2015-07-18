// You can edit this code!
// Click here and start typing.
package main

import "fmt"

func main() {
	hello()

	str("string")
	str("あいう")
}

func hello() {
	fmt.Println("Hello, 世界")
}

func str(x string) {
	fmt.Println("string = |", x, "|, len = ", len(x));
}

