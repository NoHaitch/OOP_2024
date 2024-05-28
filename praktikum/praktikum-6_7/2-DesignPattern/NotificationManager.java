import java.util.ArrayList;
import java.util.List;

public class NotificationManager {
    private List<Service> services;

    public NotificationManager(List<Service> services) {
        this.services = new ArrayList<>();
    }

    public void addService(Service service) {
        // Tambahkan service ke dalam list services
        services.add(service);
    }

    public List<Service> getServices() {
        // Mengembalikan list services
        return services;
    }

    public void removeService(Service service) {
        // Hapus service dari dalam list services
        services.remove(service);
    }

    public void notifyService(String message) {
        // Kirim pesan ke user dengan isi pesan message
        for(Service service: services){
            service.sendMessage(message);
        }
    }
}
