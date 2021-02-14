## json_parse

Needed something simple to find JSON errors


### build

    git clone https://github.com/nlohmann/json.git

    g++ -Ipath/to/json/include/ -Wall -Wextra -std=c++11 json_parse.cpp -o json_parse

    See BUF_SIZE. Defined at 8192 bytes.

### environments

    RHEL 8 x86_64, g++ 8.3.1
    Ubuntu 16.04 x86_64, g++ 7.5.0
    Ubuntu 20.10 arm64, g++ 10.2.0

### usage

    > json_parse FILE
    > cat FILE | json_parse

### example

    > cat test_file
    {"fname": "John", "lname": "Doe", "age": 50}
    {"fname": "Jane", "lname": "Doe", "age: 50}
    > cat test_file | ./json_parse

    {"fname": "Jane", "lname": "Doe", "age: 50}

    ERROR: [json.exception.parse_error.101] parse error at line 2, column 0: syntax error while parsing object key - invalid string: control character U+000A (LF) must be escaped to \u000A or \n; last read: '"age: 50}<U+000A>'; expected string literal
    line: 2
    byte position: 44

    objects: 2
    success: 1
       fail: 1
    >

