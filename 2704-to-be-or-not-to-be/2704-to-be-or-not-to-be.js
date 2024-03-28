/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {

   var obj = {
        toBe : function(chk){
            if(val===chk)  return true;
            else throw new Error("Not Equal");
        },
        notToBe : function(chk){
            if(val!==chk)  return true;
            else throw new Error("Equal");
        }
   };
   return obj;
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */