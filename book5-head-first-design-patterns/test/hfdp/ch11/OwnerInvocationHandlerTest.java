package hfdp.ch11;

import cl.mbassale.hfdp.ch11.protectionProxy.OwnerInvocationHandler;
import cl.mbassale.hfdp.ch11.protectionProxy.Person;
import cl.mbassale.hfdp.ch11.protectionProxy.PersonImpl;
import org.junit.jupiter.api.Test;

import java.lang.reflect.Proxy;

import static org.junit.jupiter.api.Assertions.*;

class OwnerInvocationHandlerTest {

    Person getOwnerProxy(Person person) {
        return (Person) Proxy.newProxyInstance(person.getClass().getClassLoader(), person.getClass().getInterfaces(), new OwnerInvocationHandler(person));
    }

    @Test
    void testInvoke() {
        Person person = new PersonImpl();
        person.setName("Marco Bassalett");
        person.setGender("Male");
        person.setInterests("Technology, cooking");
        person.setGeekRating(5);

        Person ownerProxy = getOwnerProxy(person);
        assertThrows(Exception.class, () -> ownerProxy.setGeekRating(3));
        assertDoesNotThrow(ownerProxy::getGeekRating);
    }
}