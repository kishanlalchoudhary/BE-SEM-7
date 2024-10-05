// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Bank {
    // Mapping to store balance of each customer
    mapping(address => uint) private balances;

    // Deposit function to add money to an account
    function deposit() public payable {
        require(msg.value > 0, "You must deposit some amount");
        balances[msg.sender] += msg.value;
    }

    // Withdraw function to remove money from an account
    function withdraw(uint amount) public {
        require(balances[msg.sender] >= amount, "Insufficient balance");
        balances[msg.sender] -= amount;
        payable(msg.sender).transfer(amount);
    }

    // Function to view balance
    function getBalance() public view returns (uint) {
        return balances[msg.sender];
    }
}