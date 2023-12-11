# State_Machines_and_Computability

https://ncatlab.org/nlab/show/partial+recursive+function
https://ncatlab.org/nlab/show/computable+function
https://ncatlab.org/nlab/show/partial+function

A partial recursive function is a partial function of natural numbers which can be defined by an algorithm or computer program (e.g., a Turing machine), taking finitely many natural numbers as inputs, and which on input may run forever, but otherwise eventually halts and returns a natural number as output.

### Definition of Partial Recursive Functions

A partial recursive function is a partial function from $\mathbb{N}^k$ to $\mathbb{N}$ (where $\mathbb{N}$ denotes the set of natural numbers and $k \geq 0$ is finite). It belongs to the smallest class $\mathcal{C}$ of partial functions that:

1. Includes all constant functions $1 \to \mathbb{N}$.
2. Includes all projection maps $\pi_i: \mathbb{N}^k \to \mathbb{N}$, for $i = 1, \ldots, k$.
3. Includes the successor function $s: \mathbb{N} \to \mathbb{N}$.
4. Is closed under composition: If $f_1, \ldots, f_n: \mathbb{N}^{k} \to \mathbb{N}$ and $g: \mathbb{N}^n \to \mathbb{N}$ belong to $\mathcal{C}$, then $g \circ (f_1, \ldots, f_n): \mathbb{N}^{k} \to \mathbb{N}$ also belongs to $\mathcal{C}$.
5. Is closed under primitive recursion: If $g: \mathbb{N}^k \to \mathbb{N}$ and $h: \mathbb{N}^{k+2} \to \mathbb{N}$ belong to $\mathcal{C}$, then the function $f: \mathbb{N}^{k+1} \to \mathbb{N}$ defined recursively by $f(0, \mathbf{x}) = g(\mathbf{x})$ and $f(y+1, \mathbf{x}) = h(y, f(y, \mathbf{x}), \mathbf{x})$ also belongs to $\mathcal{C}$.
6. Is closed under minimization: For any _total_ function $f: \mathbb{N}^{k+1} \to \mathbb{N}$ in $\mathcal{C}$, the partial function $g: \mathbb{N}^k \to \mathbb{N}$, defined by $g(\mathbf{x}) = c$ iff $f(c, \mathbf{x}) = 0$ and $f(d, \mathbf{x}) > 0$ for $0 \leq d < c$, also belongs to $\mathcal{C}$.

### Bare-Bones Programming Language 

A bare-bones programming language has the following characteristics:

- **Data Type**: The only required data type is nonnegative integers.
- **Assignment Statements**: It contains two assignment statements - `incr name;` (increments the value of `name` by 1) and `decr name;` (decrements the value by 1, but stays at 0 if already at 0).
- **Control Statement**: A loop control statement `while name ≠ 0 do; ... end;`, indicating repetition of statements within the loop as long as the value of `name` is not 0.
- **Simplicity**: The language is extremely simple, focusing on incrementing and decrementing values and looping based on these values.

This language can express any partial recursive function, ensuring that it has enough expressive power for any algorithmically solvable problem. The Church-Turing thesis supports this by suggesting that any language with these basic features can express solutions to all computable problems.

### Expressive Power of Programming Languages

The expressive power of a programming language is tied to its ability to compute these functions. Any language that can perform basic operations like incrementing/decrementing values and looping (while structure) can express solutions to algorithmically solvable problems. Thus, the expressive power of a programming language is more about its ability to represent these basic operations than about its complexity or higher-level features.


---

**Theorem: Partial Recursive Implies Bare-Bones Programmability**

**Objective:**
Our goal is to establish that any partial recursive function can be computed by a program in a bare-bones programming language.

**Bare-Bones Language Overview:**
- **Data Types**: Only nonnegative integers are used.
- **Variables**: Automatically declared upon first use.
- **Operations**: Increment (`incr`) and decrement (`decr`).
- **Control Structures**: A single loop construct (`while`).

**Convention for Function Representation:**
- To compute a function \( f: \mathbb{N}^M \to \mathbb{N}^N \), identifiers \( X_1, ..., X_M \) are used for inputs and \( Z_1, ..., Z_N \) for outputs.

**Computing Initial Functions:**
- Zero function \( \sigma \) is implemented as `clear Z;`.
- Successor function \( S \) is implemented as:
  ```
  Z_1 ← X_i;
  incr Z_1;
  ```
- Projection function \( P_i^j \) is implemented as `Z_1 ← X_j;`.

**Programs Representing Basic Operations (Figure 4.15):**
- **Copy Operation**: The program to copy the value from `name1` to `name2` is given as:
  ```
  clear aux;
  clear name2;
  name1 aux = 0;
  do;
    decr name1;
    incr aux;
    incr name2;
  while aux ≠ 0 do;
    decr aux;
    incr name1;
  end;
  ```

**General Partial Recursive Functions:**
- For functions computed by programs \( F \) and \( G \), concatenate \( G \) onto \( F \) and adjust outputs from \( F \) to serve as inputs to \( G \).

**Program for Primitive Recursion (Figure 4.16):**
- The program to compute a function defined by primitive recursion is:
  ```
  clear X_m+1;
  while Y ≠ 0 do;
    incr X_m+1;
    G
  end;
  Z_1 ← X_m+1;
  ```

**Program for Minimization (Figure 4.17):**
- To compute \( \mu y[g(x, y) = 0] \), the program is:
  ```
  clear X_n+1;
  G;
  while Z_1 ≠ 0 do;
    incr X_n+1;
    G;
  end;
  Z_1 ← X_n+1;
  ```

**Conclusion:**
We have structured a proof that demonstrates the computability of any partial recursive function using a bare-bones programming language. This is supported by the Church-Turing thesis, which asserts that any algorithmically solvable problem can be solved using a language that allows for nonnegative integer manipulation, incrementing, decrementing, and looping. Additional features in a programming language provide convenience but are not necessary for computational completeness.
