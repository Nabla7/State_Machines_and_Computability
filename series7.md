# Q1
Let's simplify the given grammar by removing useless symbols.

Given grammar:
1. \( S -> AB|CA \)
2. \( A -> a \)
3. \( B -> BC|AB \)
4. \( C -> ab|b \)

**Step 1:** Identify non-terminals from which terminals can be derived.

Starting with the given productions:
1. From \( A \), we can derive the terminal \( a \).
2. From \( C \), we can derive the terminals \( ab \) and \( b \).

Thus, initially, \( \{A, C\} \) are the non-terminals from which terminals can be derived.

Using the above information, we can further deduce:
1. From \( B \), using the production \( B -> BC \), we can derive \( b \) since \( C \) derives \( b \).
2. From \( S \), using the production \( S -> AB \), we can derive \( a \) and \( b \) since both \( A \) and \( B \) can derive terminals.

After this iteration, the set of non-terminals from which terminals can be derived becomes \( \{A, B, C\} \). No new non-terminals can be added, so we move to the next step.

**Step 2:** Identify non-terminals that are reachable from the start symbol.

Starting from \( S \):
1. \( S \) can reach \( A \) and \( B \) using the production \( S -> AB \).
2. \( S \) can also reach \( C \) using the production \( S -> CA \).
3. \( B \) can reach \( A \) and \( C \) using the production \( B -> AB \) and \( B -> BC \), respectively.

Therefore, all non-terminals \( \{A, B, C\} \) are reachable from \( S \).

**Step 3:** Eliminate useless symbols.

From the above steps, all non-terminals \( \{A, B, C\} \) are useful as they can derive terminals and are reachable from \( S \). So, we don't need to remove any production.

**Final Simplified Grammar:**
1. \( S -> AB|CA \)
2. \( A -> a \)
3. \( B -> BC|AB \)
4. \( C -> ab|b \)

The grammar remains unchanged as all the symbols are useful.

# Q2

Given grammar:
1. \( S -> ASB|\varepsilon \)
2. \( A -> aAS|a \)
3. \( B -> SbS|A|bb \)

### a. Elimineer \( \varepsilon \)-productieregels.

To eliminate the \( \varepsilon \)-productions (productions that generate the empty string), we first identify the nullable variables (non-terminals that can produce \( \varepsilon \)).

From the given grammar, we can deduce:
1. \( S \) is nullable because \( S -> \varepsilon \).
2. \( B \) is nullable because \( B -> A \) and \( A -> a \), but \( A \) does not produce \( \varepsilon \), so we don't consider \( A \) as nullable.

Now, we will add new productions for the nullable variables:

1. \( S -> ASB|A|SB|SbS|B \)
2. \( A -> aAS|aA|aS|a \)
3. \( B -> SbS|Sb|bS|A|bb \)

### b. Elimineer unit producties.

To eliminate unit productions, we will first identify all unit pairs:

1. \( (S, A) \): From \( S -> A \)
2. \( (S, B) \): From \( S -> B \)
3. \( (B, A) \): From \( B -> A \)

Now, replace the unit productions with equivalent productions:

For \( S -> A \), we add:
1. \( S -> aAS|aA|aS|a \)

For \( S -> B \), we add:
1. \( S -> SbS|Sb|bS|bb \)

For \( B -> A \), we add:
1. \( B -> aAS|aA|aS|a \)

### c. Zijn er nutteloze symbolen? Zo ja elimineer ze.

By looking at the grammar, all symbols can produce terminal strings and are reachable from the start symbol. So, there are no useless symbols.

### d. Zet de grammatica om in CNF (Chomsky Normal Form).

To convert the grammar to CNF, we need to ensure that every production is of the form \( A -> BC \) or \( A -> a \), where A, B, and C are non-terminals and a is a terminal.

For simplicity, we'll introduce new non-terminals for terminals:
1. \( X_a -> a \)
2. \( X_b -> b \)

Now, replace terminals in the grammar:

1. \( S -> AX_aS|X_aA|AS|X_a \)
2. \( A -> X_aAX_a|X_aA|X_aS|X_a \)
3. \( B -> SS|SX_b|X_bS|X_bX_b \)

Now, further break down productions that aren't in CNF:

1. \( S -> AX_aS|X_aA|AS|X_a \)
2. \( A -> X_aAX_a|X_aA|X_aS|X_a \)
3. \( B -> SS|SX_b|X_bS|X_bX_b \)
4. \( S1 -> AX_a \) (New production)
5. \( A1 -> AX_a \) (New production)
6. \( B1 -> X_bS \) (New production)

Replace productions in the grammar:

1. \( S -> S1S|X_aA|AS|X_a \)
2. \( A -> A1X_a|X_aA|X_aS|X_a \)
3. \( B -> SS|SX_b|B1|X_bX_b \)
4. \( S1 -> AX_a \)
5. \( A1 -> AX_a \)
6. \( B1 -> X_bS \)

Now, the grammar is in CNF. 

# Q3

Given string: `abbc`

We'll create a table of size 4x4 to represent substrings of varying lengths. Let's denote this table as `T`.

Initialize the diagonals:

```
|   | 1  | 2  | 3  | 4  |
|---|----|----|----|----|
| 1 | A  | S  |    | S  |
| 2 |    | B  | B  | B,C|
| 3 |    |    | B  | C  |
| 4 |    |    |    | A,C|
```

**Explanations:**

1. \( A \) produces `a`, so T[1,1] contains \( A \).
2. \( B \) produces `b`, so T[2,2] and T[3,3] contain \( B \).
3. \( A \) and \( C \) produce `c`, so T[4,4] contains \( A \) and \( C \).

Fill in the table:

For substring `ab` (T[1,2]):
- \( S -> AB \) can generate `ab`. So, T[1,2] contains \( S \).

For substring `bb` (T[2,3]):
- \( C \) doesn't produce `b`. Thus, T[2,3] remains as \( B \).

For substring `bc` (T[3,4]):
- \( C -> CB \) can generate `bc`. So, T[3,4] contains \( C \).

For substring `abb` (T[1,3]):
- No suitable production for both splits `a|bb` and `ab|b`.

For substring `bbc` (T[2,4]):
- \( B -> BC \) generates `bbc`. So, T[2,4] contains \( B \).

For substring `abbc` (T[1,4]):
- \( S -> AB \) can generate `abbc`. So, T[1,4] contains \( S \).

Since the top-right cell, T[1,4], contains the start symbol \( S \), the string `abbc` is in the language of the grammar.


