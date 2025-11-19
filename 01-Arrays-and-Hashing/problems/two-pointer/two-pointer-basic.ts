function sumpair(targetArray: number[], targetNumber: number = 0): boolean {
    for (let i = 0; i < targetArray.length; i++) {
        for (let j = i + 1; j < targetArray.length; j++) {
            let validationNumber = targetArray[i] + targetArray[j];

            if (validationNumber === targetNumber) {
                return true;
            }
        }
    }
    return false;
}

let targetArray = [0, 1, 2, 3, 4, 5, 6];
let targetNumber = 11;

console.log(sumpair(targetArray, targetNumber)); 