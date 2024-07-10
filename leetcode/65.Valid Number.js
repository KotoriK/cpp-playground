/**
 * @param {string} s
 * @return {boolean}
 */
var isNumber = function(s) {
    return /^[+-]?(?:\d+\.?\d*|\d*\.\d+)(?:(?!^)e[+-]?\d+)?$/i.test(s)
};