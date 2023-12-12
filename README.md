# State_Machines_and_Computability

```
https://ncatlab.org/nlab/show/partial+recursive+function
https://ncatlab.org/nlab/show/computable+function
https://ncatlab.org/nlab/show/partial+function
```

## Pal Clip 5 : Partial Recursive Functions and Bare Bones Programming Language Equivalence

A partial recursive function is a partial function of natural numbers which can be defined by an algorithm or computer program (e.g., a Turing machine), taking finitely many natural numbers as inputs, and which on input may run forever, but otherwise eventually halts and returns a natural number as output.

### Definition of Partial Recursive Functions

A partial recursive function is a partial function from $\mathbb{N}^k$ to $\mathbb{N}$ (where $\mathbb{N}$ denotes the set of natural numbers and $k \geq 0$ is finite). It belongs to the smallest class $\mathcal{C}$ of partial functions that:

1. Includes all constant functions $1 \to \mathbb{N}$.
2. Includes all projection maps $\pi_i: \mathbb{N}^k \to \mathbb{N}$, for $i = 1, \ldots, k$.
3. Includes the successor function $s: \mathbb{N} \to \mathbb{N}$.
4. Is closed under composition: If $f_1, \ldots, f_n: \mathbb{N}^{k} \to \mathbb{N}$ and $g: \mathbb{N}^n \to \mathbb{N}$ belong to $\mathcal{C}$, then $g \circ (f_1, \ldots, f_n): \mathbb{N}^{k} \to \mathbb{N}$ also belongs to $\mathcal{C}$.
5. Is closed under primitive recursion: If $g: \mathbb{N}^k \to \mathbb{N}$ and $h: \mathbb{N}^{k+2} \to \mathbb{N}$ belong to $\mathcal{C}$, then the function $f: \mathbb{N}^{k+1} \to \mathbb{N}$ defined recursively by $f(0, \mathbf{x}) = g(\mathbf{x})$ and $f(y+1, \mathbf{x}) = h(y, f(y, \mathbf{x}), \mathbf{x})$ also belongs to $\mathcal{C}$.
6. Is closed under minimization: For any _total_ function $g: \mathbb{N}^{k+1} \to \mathbb{N}$ in $\mathcal{C}$, the partial function $f: \mathbb{N}^k \to \mathbb{N}$, defined by $f(\mathbf{x}) = c$ iff $g(c, \mathbf{x}) = 0$ and $g(d, \mathbf{x}) > 0$ for $0 \leq d < c$, also belongs to $\mathcal{C}$.

**Minimization Process:**

1. **Function Construction:** 
   - A function $f:\mathbb{N}^N \to \mathbb{N}$ is constructed from another function $g:\mathbb{N}^{N+1} \to \mathbb{N}$.
   - The new function $f(x)$ is defined as the smallest $y$ in $\mathbb{N}$ such that $g(x, y) = 0$ and $g(x, z)$ is defined for all $z < y$.

2. **Notation and Interpretation:**
   - This is formally represented as $f(x) = \mu y[g(x, y) = 0]$, read as "f(x) is the smallest nonnegative integer y for which g(x, y) is zero and g(x, z) is defined for all nonnegative integers z less than y."

**Computability and Minimization:**

- If $g$ is a computable function, then the minimization of $g, \mu y[g(x, y) = 0]$, is computed by iteratively calculating $g(x, 0), g(x, 1), g(x, 2)$, and so on, until a value of 0 is obtained or a non-defined value is reached.
- If $g(x, z)$ is never zero for any $z$, then $f(x)$ is undefined.
- If $g(x, z)$ equals zero for some $z$, then $f(x)$ is defined and equals that $z$.

**Conclusion:**

Minimization is a tool used to define partial recursive functions, with it we can construct functions that may be undefined for some inputs, while also allowing the creation of total functions. When applied to computable functions, minimization ensures that the resulting function remains within the scope of partial recursive functions.

### Bare-Bones Programming Language 

A bare-bones programming language has the following characteristics:

- **Data Type**: The only required data type is nonnegative integers.
- **Assignment Statements**: It contains two assignment statements - `incr name;` (increments the value of `name` by 1) and `decr name;` (decrements the value by 1, but stays at 0 if already at 0).
- **Control Statement**: A loop control statement `while name ≠ 0 do; ... end;`, indicating repetition of statements within the loop as long as the value of `name` is not 0.
- **Simplicity**: The language is extremely simple, focusing on incrementing and decrementing values and looping based on these values.

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
- To compute a function $f: \mathbb{N}^M \to \mathbb{N}^N$, identifiers $X_1, ..., X_M$ are used for inputs and $Z_1, ..., Z_N$ for outputs.

**Computing Initial Functions:**
- Zero function (example of a constant function) $\sigma$ is implemented as `clear Z;`.
- Successor function $S$ is implemented as:
  ```
  Z_1 ← X_i;
  incr Z_1;
  ```
- Projection function $P_i^j$ is implemented as:
   ```
   clear Z;       // Initialize Z to 0
   while X_i ≠ 0 do;
     incr Z;      // Increment Z to match the value of X_i
     decr X_i;    // Decrement X_i to continue the loop until X_i is 0
   end;
   while Z ≠ 0 do; // Restore the original value of X_i
     incr X_i;
     decr Z;
   end;
   ```
- Now we have shown that constant functions, successor functions and projection functions can be expressed in the bare bones language.

**General Partial Recursive Functions:**
- The computational capabilities of the bare-bones language extend to the synthesis of general partial recursive functions. This is established by combining simpler functions into more complex ones, as illustrated by the following constructions:

**Composition**
- For functions computed by programs $F$ and $G$, concatenate $G$ onto $F$ and adjust outputs from $F$ to serve as inputs to $G$.

**Primitive Recursion Construction:**
- Consider the situation where program $G$ computes a partial function $g: \mathbb{N}^k \to \mathbb{N}^m$, and program $H$ computes another function $h: \mathbb{N}^{k+m+1} \to \mathbb{N}^m$. A third function $f: \mathbb{N}^{k+1} \to \mathbb{N}^m$ can be defined by primitive recursion:


$f(\mathbf{x}, 0) = g(\mathbf{x})$


$f(\mathbf{x}, y + 1) = h(\mathbf{x}, y, f(\mathbf{x}, y))$

- The program to compute $f$, as delineated in Figure 4.16, assumes that $G$ and $H$ are side-effect-free.

**Program for Primitive Recursion (Figure 4.16):**
- The bare-bones language facilitates the encoding of the primitive recursive function $f$ via the following program structure, reflecting the recursive definition:

```plaintext
G  
aux←X_{k+1};  
clear X_{k+1};  
while aux ≠ 0 do;  
    X_{k+2}←Z_1;  
    X_{k+3}←Z_2;  
    ·  
    ·  
    ·  
    X_{k+m+1}←Z_m;  
    H  
    incr X_{k+1};  
    decr aux;  
end;  

```

- The execution of program $G$ at the beginning corresponds to computing the base case of the function $f$, which is $f(\mathbf{x}, 0) = g(\mathbf{x})$. This is where $f$ is defined for the initial condition when the recursion 'depth' (second argument) is zero.

- The `while` loop and the execution of program $H$ within this loop correspond to the recursive case of the function $f$. Each iteration of the loop represents a single step in the recursive process, where the function $f$ is defined as $f(\mathbf{x}, y + 1) = h(\mathbf{x}, y, f(\mathbf{x}, y))$. Here, $H$ computes the value of $f$ at each step, using the values from the previous step.

- The variables `aux`, `X_{k+1}`, and others are used to manage and keep track of the recursion depth and pass the intermediate results between the computations of $G$ and $H$.

- The entire sequence of operations in the code is a procedural implementation of the function $f$, as defined by the primitive recursion of the class of partial recursive functions.

**Minimization Construction:**
- If $G$ is a program within this language that calculates $g: \mathbb{N}^{k+1} \to \mathbb{N}$, we can construct a program that determines the smallest $y$ such that $g(\mathbf{x}, y) = 0$, thus performing the minimization operation.

**Program for Minimization (Figure 4.17):**
- The minimization operation $\mu y[g(\mathbf{x}, y) = 0]$ is represented in the bare-bones language as follows, aligning with the iterative nature of this operation:

```plaintext
clear X_n+1;             // Initialize the counter variable
G;                       // Compute the function g
while Z_1 ≠ 0 do;        // Check if the condition g(x, y) = 0 is met
  incr X_n+1;            // Increment the counter, searching for the minimal y
  G;                     // Re-evaluate function g with the new counter value
end;
Z_1 ← X_n+1;             // Assign the minimal satisfying y to the output variable
```
- **Initialization of Counter**: 
  - `clear X_{n+1};` - This line initializes a counter variable, `X_{n+1}`, which will be used to track the value of $y$ as the program iteratively searches for the minimal value that satisfies $g(\mathbf{x}, y) = 0$.

- **Initial Computation of Function $g$**:
  - `G;` - The program G is executed to compute the function $g$ for the initial value of the counter. This is the starting point of the search for the minimal satisfying $y$.

- **Iterative Search for Minimal $y$**:
  - `while Z_1 ≠ 0 do;` - This loop represents the core of the minimization process. It continues as long as the condition $g(\mathbf{x}, y) ≠ 0$ holds.
  - `incr X_{n+1};` - Inside the loop, the counter $X_{n+1}$ is incremented. This step simulates checking the next value of $y$ in the search for the condition $g(\mathbf{x}, y) = 0$.
  - `G;` - After incrementing the counter, program G is executed again to re-evaluate $g$ with the new counter value. This re-evaluation is essential to check if the incremented $y$ satisfies the condition.

- **Assigning the Result**:
  - `end;` - The loop ends when $g(\mathbf{x}, y) = 0$ is found, meaning the minimal $y$ has been identified.
  - `Z_1 ← X_{n+1};` - Finally, the minimal satisfying value of $y$ is assigned to the output variable $Z_1$. This value represents the result of the minimization operation $\mu y[g(\mathbf{x}, y) = 0]$.

- The program iteratively increments a counter to find the smallest value of $y$ that makes $g(\mathbf{x}, y)$ equal to zero. It simulates the principle of minimization in an iterative form.

**Conclusion:**
- The above constructs demonstrate that the class of partial recursive functions  . The language's ability to increment, decrement, and iterate over conditions, coupled with the absence of side effects, ensures the accurate computation of complex recursive functions. This complete proof substantiates the Church-Turing thesis by confirming that a language as elementary as the bare-bones language is computationally complete, capable of expressing any algorithmically solvable problem.


-----



**Theorem: Bare-Bones Programmability Implies Partial Recursive**

**Objective:**
Our goal is to establish that a bare-bones programming language can be used to create programs that can compute any partial recursive function. .

**Fundamental Language Requirements:**

A program in the bare-bones language must involve at least one of the following statements: `incr`, `decr`, or `while`. Each statement involves a variable, and collectively, these variables form a k-tuple that represents the input-output mapping of the program.

**Single Statement Programs:**

When a program consists of only one statement, there are three possibilities:

1. `incr` or `decr` statements, which compute the primitive recursive functions $\sigma$ (successor) and $pred$ (predecessor).
2. A `while` statement in the form of `while name ≠ 0 do; end;` computes the function f(name) defined as 0 if `name` is 0, and undefined otherwise.

This function is equivalent to the partial recursive function $\mu y[\text{plus}(name, y) = 0]$, proving that single-statement programs compute partial recursive functions.

**Programs with Multiple Statements:**

Considering programs with more than one statement, we apply an inductive approach:

1. The basis of induction assumes that a program with n statements computes a partial recursive function.
2. If the program with n+1 statements does not consist of one large while statement, it is a concatenation of two shorter programs, each computing a partial recursive function. By our induction hypothesis, the concatenation of these programs computes the composition of these functions, and thus, the entire program computes a partial recursive function.

**Inductive Step for Programs with While Loops:**

For a program consisting of one large `while` loop, we represent it as follows:

```
while X ≠ 0 do;
    B
end;
```

The body of this loop, B, contains fewer than n statements. By our induction hypothesis, B computes a partial recursive function $h:\mathbb{N}^k \to \mathbb{N}^k$. We assume that the variable X in the while statement is one of the components of the k-tuple manipulated by B. If X were not affected by B, the loop would never terminate, suggesting that B influences X.

Using primitive recursion, we now define the function $f:\mathbb{N}^{k+1} \to \mathbb{N}^k$ by:


$f(\mathbf{X}, 0) = ident(\mathbf{X})$


$f(\mathbf{X}, y + 1) = h(f(\mathbf{X}, y), y)$


Here, ident represents the identity function, which can be constructed from projection functions and is primitive recursive. The value of $f(\mathbf{X}, y)$ is a k-tuple produced by initializing the variables in B to $\mathbf{x}$ and executing the loop y times. The number of times B executes is $\mu y[\pi_j^k(f(\mathbf{X}, y)) = 0]$. Thus, the function $g:\mathbb{N}^k \to \mathbb{N}^k$ computed by the entire while structure is:

$g(\mathbf{X}) = f(\mathbf{X}, \mu y[\pi_j^k \circ f(\mathbf{X}, y) = 0])$

Hence, the function computed by the while structure is partial recursive.

**Conclusion:**

- The proof demonstrates that any function computed by the bare-bones language is partial recursive. This conclusion is in alignment with the Church-Turing thesis, which posits that the computable functions are precisely the partial recursive functions. The bare-bones language, with its ability to perform increments, decrements, and conditional looping, suffices to express any algorithmically solvable problem, thereby encapsulating the complete set of partial recursive functions.






