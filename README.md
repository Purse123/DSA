## Ownership
**Introduction**
- **Ownership** is rule of rust to manage memory checks by compiler.
- example of garbage collector: **c#** and **java**, regularly looks for no-longer-used memory
- **Ownership** is a new concept, Rust is unique.
**The Stack and Heap**
- Whether a value is on the stack or the heap affects rust program.
- Both **stack** and **heap** are parts of memory are used at runtime, but structured in different ways.
- **STACK**:
    1. LIFO
    2. All data stored on stack must have a known fixed size.
- **HEAP**:
    1. Less organized.
    2. Data with unkown size at compile time.
    3. when putting data, you request a certain amount of space.
    4. memory allocator finds empty spot big enough, marks it as being in use and returns a pointer, this process is called **allocating** (*pushing value on stack is not considered allocation*)
    5. Bcz pointer to heap is known *(fixed size)*, we can store the pointer on the stack.
- Pushing on stack is faster, no need to search for a place to store new data
- Accessing data is slower in heap, cz need to follow a pointer
- Keeping track of what part of code or data on the heap are using, minimizing duplicate data on heap and cleaning up unused data on heap so not to run out space, are all problems that ownership addresses.
```rust
let x = 5;        // Stack allocation
let y = Box::new(10); // Heap allocation

let r1 = &x;      // Borrow stack-allocated value
let r2 = &*y;     // Borrow heap-allocated value
```
**PHILOSOPHY**
| ASPECT             | Malloc/Calloc in C                                                                | Ownership in Rust                                                                |
| ----------------- | ------------------------------------------------------------------ | ------------------------------------------------------------------ |
| auto/manual | must explicitly allocate and free memory | memory is freed when no longer needed automatically |
| Error-Prone | Easy to free, leads to memory leaks | when out of scope memory is auto deallocate |

## Source
![README DESIGN](https://readme.so/)
![Rust official](https://doc.rust-lang.org/book/ch04-01-what-is-ownership.html)