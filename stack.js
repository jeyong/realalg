
function Stack() {
    this.arr = [];
    this.top = -1;
    this.init = init;
    this.push = push;
    this.pop = pop;
    this.size = size;
    this.toString = toString;
}

function init() {
    this.arr = [];
    this.top = -1;
}

function push(e) {
    this.arr[++this.top] = e;
}

function pop() {
    if (this.size() < 1) {
        return NaN
    }
    r = this.arr[this.top]
    this.arr = this.arr.slice(0, this.arr.length-1)
    this.top--
    return r
}

function size() {
    return this.arr.length;
}

function toString() {
    return this.arr.toString();
}

s = new Stack();
s.push(1);
s.push(2);
s.push(3);
s.push(4);
console.log(s.toString());
console.log(s.pop());
console.log(s.toString());
console.log(s.pop());
console.log(s.toString());

s.init();
console.log(s.toString());
