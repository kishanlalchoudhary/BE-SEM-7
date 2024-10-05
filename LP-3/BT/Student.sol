// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentData {
    // Structure to hold student details
    struct Student {
        uint id;
        string name;
        uint age;
    }

    // Array to hold list of students
    Student[] private students;

    // Fallback function to handle any ether sent to the contract
    fallback() external payable {
        // Ether received will be logged into the contract's balance
    }

    // Function to add a new student to the array
    function addStudent(uint _id, string memory _name, uint _age) public {
        students.push(Student(_id, _name, _age));
    }

    // Function to retrieve student details by index
    function getStudent(uint index) public view returns (uint, string memory, uint) {
        require(index < students.length, "Index out of bounds");
        Student memory s = students[index];
        return (s.id, s.name, s.age);
    }

    // Function to get the total number of students
    function getStudentCount() public view returns (uint) {
        return students.length;
    }

    // Receive ether into the contract
    receive() external payable {}
}