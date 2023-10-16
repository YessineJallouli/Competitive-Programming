import java.util.Scanner
fun main(args: Array<String>) {
    val read = Scanner(System.`in`)
    var t = read.nextInt()
    for (i in 0 until t) {
       var n = read.nextInt()
       println((n-1)/2)
    }
}