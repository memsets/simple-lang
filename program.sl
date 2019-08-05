// hello world

function foo(a, b) {
    b = b + 1
    print(b)
    while (a != 10) {
        print(a)
        a = a + 1
    }

    for (i = 0; i < 10; i = i + 1) {
        print("10раз")
    }
    return a + b
}

print(foo(5, 10))
