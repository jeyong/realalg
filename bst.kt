
fun main(args: Array<String>) {
    println("Hello")

    var t = Tree<Int>()

    t.add(1)
    t.add(2)
    t.add(3)
    t.add(4)
    t.add(5)

    t.BFT()

    var t2 = Tree<Int>()
    t2.add(10)
    t2.add(11)
    t2.add(12)
    t2.add(1)
    t2.add(2)
    t2.BFT()
}

class Node<T: Comparable<T>>(val value: T?=null) {
    var left: Node<T>? = null
    var right: Node<T>? = null
}

class Tree<T : Comparable<T>>() {
    var root: Node<T>? = null

    fun add(item: T): Unit {
        var n: Node<T> = Node<T>(item)

        if (root == null) {
            root = n
            return
        }

        var cur = root

        while (cur != null) {
            if (item > cur.value!!) {
                if (cur.right == null) {
                    cur.right = n
                    break
                }
                cur = cur.right
            } else {
                if (cur.left == null) {
                    cur.left = n
                    break
                }
                cur = cur.left
            }
        }
    }

    fun BFT() {
        if (root == null) return
        var q = mutableListOf<Node<T>>(root!!)

        while(q.size!=0){
            var cur = q.removeAt(0)
            println("${cur.value} ->")

            if (cur.left != null) {
                q.add(cur.left!!)
            }
            if (cur.right != null) {
                q.add(cur.right!!)
            }
        }
    }
}
