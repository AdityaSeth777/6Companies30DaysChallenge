/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var findTheWinner = function(n, k) {
    const array = Array.from({ length: n }, (_, index) => index + 1);
    var i=0;
    //Aditya Seth.
    while (array.length > 1) {
        i = (i + k - 1) % array.length;
        array.splice(i, 1);
    }
    return array[0]
};