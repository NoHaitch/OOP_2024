import java.lang.System;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int caseType = input.nextInt();
        switch (caseType) {
            // Bus
            case 1:
                tc1();
                break;
            case 2:
                tc2();
                break;
            case 3:
                tc3();
                break;
            case 4:
                tc4();
                break;
            case 5:
                tc5();
                break;
            case 6:
                tc6();
                break;
            case 7:
                tc7();
                break;
            case 8:
                tc8();
                break;
            case 9:
                tc9();
                break;
            case 10:
                tc10();
                break;
        }
        input.close();
    }

    private static void evaluate(boolean cond) {
        System.out.println(cond ? '1' : '0');
    }

    private static void tc1() {
        ContactManager contactManager = new ContactManager();

        try {
            contactManager.addContact(new Contact("John", "12345"));
            contactManager.addContact(new Contact("Alice", "12345"));
            contactManager.addContact(new Contact("Bob", "12345"));
            contactManager.addContact(new Contact("Charlie", "12345"));
        } catch (DuplicateContactException e) {
            System.out.println("tc1 gagal");
        }
        evaluate(contactManager.size() == 4);
        System.out.println("tc1 sukses");
    }

    private static void tc2() {
        ContactManager contactManager = new ContactManager();

        try {
            contactManager.addContact(new Contact("John", "12345"));
            contactManager.addContact(new Contact("Alice", "12345"));
            contactManager.addContact(new Contact("Bob", "12345"));
            contactManager.addContact(new Contact("Charlie", "12345"));
        } catch (DuplicateContactException e) {
            System.out.println("tc2 gagal");
        }
        try {
            Contact contact = contactManager.removeFirstContact();
            evaluate(contactManager.size() == 3);
            evaluate(contact.getName().equals("John"));
            evaluate(contact.getName().equals("Alice"));
            System.out.println("tc2 sukses");
        } catch (EmptyContactListException e) {
            System.out.println("tc2 gagal");
        }
    }

    private static void tc3() {
        ContactManager contactManager = new ContactManager();

        try {
            contactManager.addContact(new Contact("John", "12345"));
            contactManager.addContact(new Contact("Alice", "12345"));
            contactManager.addContact(new Contact("Bob", "12345"));
            contactManager.addContact(new Contact("Alice", "12345"));
        } catch (DuplicateContactException e) {
            System.out.println(e.getMessage());
        }
        System.out.println("tc3 sukses");
    }

    private static void tc4() {
        ContactManager contactManager = new ContactManager();

        try {
            contactManager.addContact(new Contact("John", "12345"));
            contactManager.addContact(new Contact("Alice", "12345"));
            contactManager.addContact(new Contact("Bob", "12345"));
            contactManager.addContact(new Contact("Charlie", "12345"));
        } catch (DuplicateContactException e) {
            System.out.println("tc4 gagal");
        }
        try {
            contactManager.displayContactsAscending();
        } catch (EmptyContactListException e) {
            System.out.println("tc4 gagal");
        }
        System.out.println("tc4 sukses");
    }

    private static void tc5() {
        ContactManager contactManager = new ContactManager();

        try {
            contactManager.addContact(new Contact("John", "12345"));
            contactManager.addContact(new Contact("Alice", "12345"));
            contactManager.addContact(new Contact("Bob", "12345"));
            contactManager.addContact(new Contact("Charlie", "12345"));
        } catch (DuplicateContactException e) {
            System.out.println("tc5 gagal");
        }
        try {
            contactManager.displayContactsDescending();
        } catch (EmptyContactListException e) {
            System.out.println("tc5 gagal");
        }
        System.out.println("tc5 sukses");
    }

    private static void tc6() {
        ContactManager contactManager = new ContactManager();

        try {
            contactManager.addContact(new Contact("John", "12345"));
            contactManager.addContact(new Contact("Alice", "12345"));
            contactManager.addContact(new Contact("Bob", "12345"));
            contactManager.addContact(new Contact("Charlie", "12345"));
        } catch (DuplicateContactException e) {
            System.out.println("tc6 gagal");
        }
        try {
            Contact c1 = contactManager.removeFirstContact();
            Contact c2 = contactManager.removeFirstContact();
            Contact c3 = contactManager.removeFirstContact();
            Contact c4 = contactManager.removeFirstContact();
            Contact c5 = contactManager.removeFirstContact();
        } catch (EmptyContactListException e) {
            System.out.println(e.getMessage());
        }
        evaluate(contactManager.size() == 0);
        System.out.println("tc6 sukses");
    }

    private static void tc7() {
        ContactManager contactManager = new ContactManager();

        try {
            contactManager.addContact(new Contact("John", "12345"));
            contactManager.addContact(new Contact("Alice", "12345"));
            contactManager.addContact(new Contact("Bob", "12345"));
            contactManager.addContact(new Contact("Charlie", "12345"));
        } catch (DuplicateContactException e) {
            System.out.println("tc7 gagal");
        }
        try {
            contactManager.removeContact("Alice");
            evaluate(contactManager.size() == 3);
        } catch (ContactNotFoundException e) {
            System.out.println("tc7 gagal");
        }
        System.out.println("tc7 sukses");
    }

    private static void tc8() {
        ContactManager contactManager = new ContactManager();

        try {
            contactManager.addContact(new Contact("John", "12345"));
            contactManager.addContact(new Contact("Alice", "12345"));
            contactManager.addContact(new Contact("Bob", "12345"));
            contactManager.addContact(new Contact("Charlie", "12345"));
        } catch (DuplicateContactException e) {
            System.out.println("tc8 gagal");
        }
        try {
            contactManager.removeContact("Alice");
            contactManager.removeContact("Alice");
        } catch (ContactNotFoundException e) {
            System.out.println(e.getMessage());
        } 
        evaluate(contactManager.size() == 3);
        System.out.println("tc8 sukses");
    }

    private static void tc9() {
        ContactManager contactManager = new ContactManager();

        try {
            contactManager.addContact(new Contact("John", "12345"));
            contactManager.addContact(new Contact("Alice", "12345"));
            contactManager.addContact(new Contact("Bob", "12345"));
            contactManager.addContact(new Contact("Charlie", "12345"));
        } catch (DuplicateContactException e) {
            System.out.println("tc9 gagal");
        }
        try {
            contactManager.removeContact("Alice");
        } catch (ContactNotFoundException e) {
            System.out.println("tc9 gagal");
        }

        try {
            Contact c = contactManager.getFirstContact();
            evaluate(c.getName().equals("Bob"));
        } catch (EmptyContactListException e) {
            System.out.println("tc9 gagal");
        }
        System.out.println("tc9 sukses");
    }

    private static void tc10() {
        ContactManager contactManager = new ContactManager();

        try {
            contactManager.getFirstContact();
        } catch (EmptyContactListException e) {
            System.out.println(e.getMessage());
        }

        evaluate(contactManager.isEmpty() == true);

        System.out.println("tc10 sukses");
    }
}
