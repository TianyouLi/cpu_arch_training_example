var iterations = process.argv[2];
if (typeof iterations === "undefined") {
    iterations = 1;
}

console.log("\n\
#include <iostream>\n\
#include <cstdlib>\n\
#include <ctime>\n\
\n\
int main(int argc, char* argv[])\n\
{\n\
    srand(time(NULL));\n\
    int result = 0;\n\
    for (int i=0; i< " + Math.floor(1000000000 / iterations) + "; i++) {\n\
        int code = (i & 1) == 0 ? i % " + iterations + ": (i + " + Math.floor(iterations / 2) + ") % " + iterations + ";\n\
        if (code == 0) {\n\
            result +=1;\n\
        }\n\
");
for (let i =1 ; i < iterations ; i++) {
    console.log("\n\
        else if (code == " + i + ") {\n\
                result += " 
            + Math.floor(Math.random() * 100) 
            + ";\n        }\n");
}        
console.log("\
    }\n\
    std::cout << result << std::endl;\n\
    return result;\n\
}");


