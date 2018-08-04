function Queue() {
    this.arr = [];
    this.head = -1;
    this.tail = -1;
    this.init = init;
    this.enqueue = enqueue;
    this.dequeue = dequeue;
    this.size = size;
    this.toString = toString;
}

function init() {
    this.arr = [];
    this.head = -1;
    this.tail = -1;
}

function enqueue(e) {
    if (this.head == -1) {
        this.head = 0;
        this.tail = 0;
        this.arr[this.tail] = e;
        return ;
    }
    this.arr[++this.tail] = e ;
}

function dequeue(e) {
    if (this.size() == 0) {
        return NaN;
    }
    r = this.arr[this.head];
    if (this.size() == 1) {
        this.init();
    }else {
        this.arr = this.arr.slice(1,this.size());
    }
    return r;
}

function size() {
    return this.arr.length;
}

function toString() {
    return this.arr.toString();
}

q = new Queue();
q.enqueue(1);
q.enqueue(2);
q.enqueue(3);
q.enqueue(4);
console.log(q.toString());

console.log(q.dequeue());
console.log(q.toString());

console.log(q.dequeue());
console.log(q.toString());

q.init();
console.log(q.toString());
q.dequeue();
