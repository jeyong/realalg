function Node(val) {
    this.val = val;
    this.left = undefined;
    this.right = undefined;
    this.toString = toString;
}

function toString() {
    return this.val.toString();
}

function Tree() {
    this.root = undefined;

    this.traversal = traversal;
    this.addNode = addNode;
}

function traversal(node) {
    if (node == undefined) {
        return ;
    }
    traversal(node.left);
    traversal(node.right);
    console.log(node.toString());
}

function addNode(val) {
    n = new Node(val);

    if (this.root == undefined) {
        this.root = n;
        return ;
    }
    cur = this.root;
    while(cur != undefined) {
        if (cur.val < val) {
            if (cur.right == undefined) {
                cur.right = n;
                return ;
            }
            cur = cur.right;
        } else {
            if (cur.left == undefined) {
                cur.left = n;
                return ;
            }
            cur = cur.left;
        }
    }
}


console.log("node Test")

n1 = new Node(1);
n2 = new Node(2);
n3 = new Node(3);

console.log(n1.toString());
console.log(n2.toString());
console.log(n3.toString());

n1.left = n2;
n1.right = n3;

console.log(n1.left.toString());
console.log(n1.right.toString());

console.log("Tree Test")
t = new Tree();
t.addNode(1);
t.addNode(2);
t.addNode(3);
t.addNode(4);
t.traversal(t.root);

