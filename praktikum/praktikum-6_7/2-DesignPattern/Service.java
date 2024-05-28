import java.util.ArrayList;
import java.util.List;

public class Service {
    private String servicePhone;
    private String serviceName;
    private String serviceEmail;
    private IMessageSender messageSender;
    private List<User> users;


    public Service(String serviceName, String serviceEmail, String servicePhone) {
        // Inisialisasi service dengan serviceName, serviceEmail, dan servicePhone, users diinisialisasi dengan list kosong
        this.serviceName = serviceName;
        this.serviceEmail = serviceEmail;
        this.servicePhone = servicePhone;
        users = new ArrayList<>();
    }

    public void addUser(User user) {
        // Tambahkan user ke dalam list users
        users.add(user);
    }

    public void sendMessage(String message) {
        // Kirim pesan ke semua user dengan isi pesan message
        // Panggil method sendMessage dari messageSender
        // Cek apakah user memiliki email, jika ada kirim email, dst. Email, device, phone yang kosong tidak perlu dikirim. Data yang kosong ditandai dengan ""
        for(User user: users){
            if(!user.getEmail().isEmpty()){
                EmailMessageSender emailMessageSender = new EmailMessageSender(serviceEmail);
                emailMessageSender.sendMessage(user, message);
            }
            if(!user.getDevice().isEmpty()){
                PushNotifMessageSender pushNotifMessageSender = new PushNotifMessageSender(serviceName);
                pushNotifMessageSender.sendMessage(user, message);
            }
            if(!user.getPhone().isEmpty()){
                SMSMessageSender smsMessageSender = new SMSMessageSender(servicePhone);
                smsMessageSender.sendMessage(user, message);
            }
        }
    }
}
