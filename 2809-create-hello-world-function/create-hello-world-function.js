/**
 * @return {Function}
 */
var createHelloWorld = function() {
    
    return function(...args) {
        let op="Hello World";
        return op;
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */