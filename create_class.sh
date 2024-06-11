#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 ClassName"
    exit 1
fi

CLASS_NAME=$1
HEADER_FILE="${CLASS_NAME}.hpp"
SOURCE_FILE="${CLASS_NAME}.cpp"

CLASS_NAME_UPPER=$(echo "${CLASS_NAME}" | tr '[:lower:]' '[:upper:]')

cat <<EOL > ${HEADER_FILE}
#ifndef ${CLASS_NAME_UPPER}_HPP
# define ${CLASS_NAME_UPPER}_HPP

class ${CLASS_NAME} 
{
    public:
        ${CLASS_NAME}(); // constructor
        ${CLASS_NAME}(const ${CLASS_NAME}& other); //copy constructor
        ${CLASS_NAME}&  operator=(${CLASS_NAME}& other); // copy assignment operator
        ~${CLASS_NAME}(); // destructor 

        // Methods: 

    private:
        // Member variables & utils functions:
};

#endif // ${CLASS_NAME}_HPP
EOL

cat <<EOL > ${SOURCE_FILE}
#include "${HEADER_FILE}"

//Constructor
${CLASS_NAME}::${CLASS_NAME}() {}

//Copy constructor
${CLASS_NAME}::${CLASS_NAME}(const ${CLASS_NAME}& other) {}

//Copy assignment operator
${CLASS_NAME}&  ${CLASS_NAME}::operator=(${CLASS_NAME}& other) {}

//Destructor
${CLASS_NAME}::~${CLASS_NAME}() {}

// Methods:
EOL

echo "Files ${HEADER_FILE} and ${SOURCE_FILE} created successfully."