# Instruction

IGameModule can communicate data to the core via the `getInstruction` method. This method returns a vector of strings. Each string is an instruction. The core will interpret these instructions and act accordingly.

## Instructions

### `displayText`

Format:

```
displayText <text> <x> <y> <highlight>
```

- `<text>`: The text to display.
- `<x>`: The x position of the text.
- `<y>`: The y position of the text.
- `<highlight>`: `true` if the text should be highlighted, `false` otherwise.

### `loadLibrary`

Format:

```
loadLibrary <libraryPath> <librarySignature>
```

- `<libraryPath>`: The path to the library to load.
- `<librarySignature>`: The signature of the library to load. See [Type.hpp](Type.hpp) for more information.

### `setScore`

```
setScore <n>
```

- `<n>`: New score
