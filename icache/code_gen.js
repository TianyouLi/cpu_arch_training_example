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
    for (int i=0; i< 100000000; i++) {\n\
        switch(rand() %" + iterations + ") {");
for (let i =0 ; i < iterations ; i++) {
    console.log("\n\
        case " + i + "\
        :\n        result += " 
            + Math.floor(Math.random() * 100) 
            + ";\n        break;\n");
}        
console.log("\
        default:\n\
            result += 0;\n\
            break;\n\
        }\n\
    }\n\
    std::cout << result << std::endl;\n\
    return result;\n\
}");


