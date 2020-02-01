
class Person {

    name = null;

    friends = []

    constructor(name = null, friends = []) {
        this.name = name;
        this.friends = friends;
    }

    add(friend) {
        this.friends.push(friend);
    }

}

const mary = new Person('Mary');
const peter = new Person('Peter');
mary.add(peter);
peter.add(mary);
console.log(mary);

