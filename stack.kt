
fun main(args: Array<String>) {
    println("Hello")
    var s = Stack<Int>()
    s.push(1)
    s.push(2)
    s.push(3)
    println(s.count())
    println(s)
    println(s.pop())
    println(s.pop())
    println(s.pop())
    println(s.pop())

    var q = Queue<Int>()
    q.insert(1)
    q.insert(2)
    q.insert(3)
    println(q)
    println(q.remove())
    println(q.remove())
    println(q.remove())
    println(q.remove())

}

class Stack<T>() {
    var items: MutableList<T> = mutableListOf()

    fun push(item: T) {
        items.add(item)
    }
    fun pop(): T? {
        if (items.isEmpty())
            return null
        var item = items.last()
        items.removeAt(items.size-1)
        return item

    }
    fun count(): Int {
        return items.size
    }
    override fun toString(): String {
        return items.toString()
    }
}

class Queue<T>() {
    var items: MutableList<T> = mutableListOf()

    fun insert(item: T) {
        items.add(item)
    }

    fun remove(): T? {
        if (items.isEmpty()) {
            return null
        }
        var item = items.removeAt(0)
        return item
    }

    fun count(): Int {
        return items.size
    }

    override fun toString(): String {
        return items.toString()
    }
}
