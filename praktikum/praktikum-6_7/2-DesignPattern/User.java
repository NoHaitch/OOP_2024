
public class User {
    private String name;
    private String email;
    private String phone;
    private String device;

    public User(String name, String email, String phone, String device) {
        this.name = name;
        this.email = email;
        this.phone = phone;
        this.device = device;
    }

    public String getName() {
        return name;
    }

    public String getEmail() {
        return email;
    }

    public String getPhone() {
        return phone;
    }

    public String getDevice() {
        return device;
    }
}
