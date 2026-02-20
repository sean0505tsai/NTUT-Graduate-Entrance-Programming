# UML class of problem 6:

## Pet
```
────────────────────────────────
                Pet
────────────────────────────────
(/*Problem 6-1*/) _weight:int
(/*Problem 6-2*/) _name:string
( /* Problem 6-3 */ )
────────────────────────────────
+ getWeight(): int
+ getName(): string
────────────────────────────────
        ( /* Problem 6-4 */ )
```

## Cat (繼承自 Pet)
```
────────────────────────────────
                Cat
────────────────────────────────
- toy: vector<string>
────────────────────────────────
- sortedByAlphabet(): void( /* Problem 6-5 */ )
+ addToy(toy: string): void
+ getToy(index: int): string
────────────────────────────────
```

## Bird (繼承自 Pet)
```
────────────────────────────────
               Bird
────────────────────────────────
- canFly: bool
( /* Problem 6-6 */ )
────────────────────────────────
``` 
