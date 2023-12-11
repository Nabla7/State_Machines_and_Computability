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

**Minimization Process:**

1. **Function Construction:** 
   - A function $\( f:\mathbb{N}^N \to \mathbb{N} \)$ is constructed from another function $\( g:\mathbb{N}^{N+1} \to \mathbb{N} \)$.
   - The new function $\( f(x) \)$ is defined as the smallest $\( y \)$ in $\( \mathbb{N} \)$ such that $\( g(x, y) = 0 \)$ and $\( g(x, z) \)$ is defined for all $\( z < y \)$.

2. **Notation and Interpretation:**
   - This is formally represented as $\( f(x) = \mu y[g(x, y) = 0] \)$, read as "f(x) is the smallest nonnegative integer y for which g(x, y) is zero and g(x, z) is defined for all nonnegative integers z less than y."

**Examples of Minimization:**

1. **Undefined Values:**
   - If there is no such $\( y \)$ that satisfies $\( g(x, y) = 0 \)$, then $\( f(x) \)$ is undefined.

2. **Integer Quotient Function via Minimization:**
   - The integer quotient function, which is the integer portion of $\( x/y \)$ if $\( y \neq 0 \)$, is undefined if $\( y = 0 \)$.
   - This function can be constructed using minimization as $\( \text{div}(x, y) = \mu t[(x + 1) - ((\text{mult}(t, y) + y)) = 0] \)$, where $\( \text{mult} \)$ is a function representing multiplication.

3. **Total Functions from Minimization:**
   - Minimization can also produce total functions, such as the identity function $\( f(x) = \mu y[\text{monus}(x, y) = 0] \)$, where $\( \text{monus} \)$ is a monus operation (modified subtraction).

**Computability and Minimization:**

- If $\( g \)$ is a computable function, then the minimization of $\( g \), \( \mu y[g(x, y) = 0] \)$, is computed by iteratively calculating $\( g(x, 0) \), \( g(x, 1) \), \( g(x, 2) \)$, and so on, until a value of 0 is obtained or a non-defined value is reached.
- If $\( g(x, z) \)$ is never zero for any $\( z \)$, then $\( f(x) \)$ is undefined.
- If $\( g(x, z) \)$ equals zero for some $\( z \)$, then $\( f(x) \)$ is defined and equals that $\( z \)$.

**Conclusion:**

Minimization is a powerful tool in defining partial recursive functions, illustrating the capability to construct functions that may be undefined for some inputs, while also allowing the creation of total functions. When applied to computable functions, minimization ensures that the resulting function remains within the scope of partial recursive functions.

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
- To compute a function $\( f: \mathbb{N}^M \to \mathbb{N}^N \)$, identifiers $\( X_1, ..., X_M \)$ are used for inputs and $\( Z_1, ..., Z_N \)$ for outputs.

**Computing Initial Functions:**
- Zero function $\( \sigma \)$ is implemented as `clear Z;`.
- Successor function $\( S \)$ is implemented as:
  ```
  Z_1 ← X_i;
  incr Z_1;
  ```
- Projection function $\( P_i^j \)$ is implemented as `Z_1 ← X_j;`.

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
- For functions computed by programs $\( F \)$ and $\( G \)$, concatenate $\( G \)$ onto $\( F \)$ and adjust outputs from $\( F \)$ to serve as inputs to $\( G \)$.

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
- To compute $\( \mu y[g(x, y) = 0] \)$, the program is:
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


-----



**Theorem: Bare-Bones Programmability Implies Partial Recursive**

**Overview of the Bare-Bones Language's Capabilities:**

The surprising computational strength of the bare-bones language raises a conjecture about its limitations. If the language could compute functions beyond what is partial recursive, it would contradict the Church-Turing thesis. However, the bare-bones language is indeed bound by the capabilities of partial recursive functions.

**Fundamental Language Requirements:**

A program in the bare-bones language must involve at least one of the following statements: `incr`, `decr`, or `while`. Each statement involves a variable, and collectively, these variables form a k-tuple that represents the input-output mapping of the program.

**Single Statement Programs:**

When a program consists of only one statement, there are three possibilities:

1. `incr` or `decr` statements, which compute the primitive recursive functions $\( \sigma \)$ (successor) and $\( pred \)$ (predecessor).
2. A `while` statement in the form of `while name ≠ 0 do; end;` computes the function \( f(name) \) defined as 0 if `name` is 0, and undefined otherwise.

This function is equivalent to the partial recursive function $\( \mu y[\text{plus}(name, y) = 0] \)$, proving that single-statement programs compute partial recursive functions.

**Programs with Multiple Statements:**

Considering programs with more than one statement, an inductive approach is used:

1. The basis of induction assumes that a program with `n` statements computes a partial recursive function.
2. When a program with `n+1` statements is considered, the inductive hypothesis applies to the first `n` statements, and the additional statement is handled separately.

**Inductive Step for Programs with While Loops:**

A program consisting of a single large `while` loop can be represented as:

```
while X ≠ 0 do;
    B
end;
```

Here, `B` represents the body of the loop, which contains fewer than `n` statements. The inductive hypothesis implies that `B` computes a partial recursive function. When the loop is entered, it represents a function that combines primitive recursion with the identity function, as follows:

- If `X` is 0, the function computed is the identity function.
- If `X` is not 0, the function represented by the loop is a composition of functions computed within `B`.

The entire while structure computes the function $\( g(X) = f(X, \mu y[f'(X, y) = 0]) \)$, where $\( f' \)$ is the function computed by `B` and $\( g \)$ is the function computed by the entire while structure. Thus, the function computed by the while structure is partial recursive.

**Conclusion of the Proof:**

The proof concludes that any function computed by the bare-bones language, even with multiple statements and loops, is partial recursive. This supports the Church-Turing thesis, affirming that the bare-bones language's expressiveness is constrained to partial recursive functions. No programming language, regardless of its simplicity or complexity, exceeds the computational expressiveness afforded by partial recursive functions. The proof asserts that the bare-bones language is sufficient for algorithmic problem-solving within the bounds of partial recursive functions.


The provided text discusses the concept of partial recursive functions and the process of minimization, which is a method to define functions within the framework of computability theory. The text can be structured more formally as follows:

---






