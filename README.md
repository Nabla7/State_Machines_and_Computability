# State_Machines_and_Computability


A partial recursive function is a partial function of natural numbers which can be defined by an algorithm or computer program (e.g., a Turing machine), taking finitely many natural numbers as inputs, and which on input may run forever, but otherwise eventually halts and returns a natural number as output.

### Definition of Partial Recursive Functions

A partial recursive function is a partial function from \(\mathbb{N}^k\) to \(\mathbb{N}\) (where \(\mathbb{N}\) denotes the set of natural numbers and \(k \geq 0\) is finite). It belongs to the smallest class \(\mathcal{C}\) of partial functions that:

1. Includes all constant functions \(1 \to \mathbb{N}\).
2. Includes all projection maps \(\pi_i: \mathbb{N}^k \to \mathbb{N}\), for \(i = 1, \ldots, k\).
3. Includes the successor function \(s: \mathbb{N} \to \mathbb{N}\).
4. Is closed under composition: If \(f_1, \ldots, f_n: \mathbb{N}^{k} \to \mathbb{N}\) and \(g: \mathbb{N}^n \to \mathbb{N}\) belong to \(\mathcal{C}\), then \(g \circ (f_1, \ldots, f_n): \mathbb{N}^{k} \to \mathbb{N}\) also belongs to \(\mathcal{C}\).
5. Is closed under primitive recursion: If \(g: \mathbb{N}^k \to \mathbb{N}\) and \(h: \mathbb{N}^{k+2} \to \mathbb{N}\) belong to \(\mathcal{C}\), then the function \(f: \mathbb{N}^{k+1} \to \mathbb{N}\) defined recursively by \(f(0, \mathbf{x}) = g(\mathbf{x})\) and \(f(y+1, \mathbf{x}) = h(y, f(y, \mathbf{x}), \mathbf{x})\) also belongs to \(\mathcal{C}\).
6. Is closed under minimization: For any _total_ function \(f: \mathbb{N}^{k+1} \to \mathbb{N}\) in \(\mathcal{C}\), the partial function \(g: \mathbb{N}^k \to \mathbb{N}\), defined by \(g(\mathbf{x}) = c\) iff \(f(c, \mathbf{x}) = 0\) and \(f(d, \mathbf{x}) > 0\) for \(0 \leq d < c\), also belongs to \(\mathcal{C}\).

### Bare-Bones Programming Language 

A bare-bones programming language has the following characteristics:

- **Data Type**: The only required data type is nonnegative integers.
- **Assignment Statements**: It contains two assignment statements - `incr name;` (increments the value of `name` by 1) and `decr name;` (decrements the value by 1, but stays at 0 if already at 0).
- **Control Statement**: A loop control statement `while name ≠ 0 do; ... end;`, indicating repetition of statements within the loop as long as the value of `name` is not 0.
- **Simplicity**: The language is extremely simple, focusing on incrementing and decrementing values and looping based on these values.

This language can express any partial recursive function, ensuring that it has enough expressive power for any algorithmically solvable problem. The Church-Turing thesis supports this by suggesting that any language with these basic features can express solutions to all computable problems.

### Expressive Power of Programming Languages

The expressive power of a programming language is tied to its ability to compute these functions. Any language that can perform basic operations like incrementing/decrementing values and looping (while structure) can express solutions to algorithmically solvable problems. Thus, the expressive power of a programming language is more about its ability to represent these basic operations than about its complexity or higher-level features.
