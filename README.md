# sha0
This is an implementation of the SHA-0 algorithm. Note that SHA-0 is a BROKEN
algorithm; this program has been created to verify old, broken signatures.

## Credits
The whole thing is based on RFC6234 (which contains a reference implementation
of SHA-1). It has been put into compilable code by Tom Szilagyi (@tomszilagyi)
[in his GitHub project](https://github.com/tomszilagyi/rfc6234). The hint of
what code changes turn SHA-1 into SHA-0 have been taken from StackExchange
fgrieu, who 
[did an excellent outline on the code differences](https://crypto.stackexchange.com/questions/62055/where-can-i-find-the-description-of-sha0-algorithm).
I'm basically just the monkey gluing pieces together :)

## Usage
```
$ echo -n foobar >foobar
$ ./sha0 foobar
SHA0 over 6 bytes of foobar: d3fb2f31117cc1481f6c5dc1905e06892a8ca38b
```

## License
IETF license, see LICENSE file.
