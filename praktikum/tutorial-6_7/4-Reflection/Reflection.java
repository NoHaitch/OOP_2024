import java.util.ArrayList;
import java.util.List;
import java.lang.reflect.*;;

public class Reflection{
    //TIDAK BOLEH MENGUBAH NAMA METHOD YANG SUDAH ADA DAN PARAMS SERTA INPUT TYPENYA
    //BOLEH MENAMBAHKAN PRIVATE / PROTECTED METHOD SESUAI DENGAN KEBUTUHAN
    //DI LUAR SANA ADA KELAS YANG NAMANYA Ghost DAN Secret.

    public ArrayList<String> ghostMethods() throws Exception{
        // Get the class using wildcard
        Class<?> ghostClass = Class.forName("Ghost");

        // get list of methods
        Method[] ghostMethods = ghostClass.getDeclaredMethods();
        ArrayList<String> ghostMethodsName = new ArrayList<String>();
        for (Method method : ghostMethods) {
            ghostMethodsName.add(method.getName());
        }
        
        return ghostMethodsName;
    }   

    public Integer sumGhost() throws Exception{
        // 
        Class<?> ghostClass = Class.forName("Ghost");
        Method[] ghostMethods = ghostClass.getDeclaredMethods();
        Integer sum = 0;
        for (Method method : ghostMethods) {
            method.setAccessible(true);
            if (method.getReturnType().equals(Integer.class)) {
                Integer result = (Integer) method.invoke(ghostClass.newInstance());
                sum += result;
            }
        }
        return sum;
    }

    public String letterGhost() throws Exception{
        Class<?> ghostClass = Class.forName("Ghost");
        Method[] ghostMethods = ghostClass.getDeclaredMethods();
        String concat = "";
        for (Method method : ghostMethods) {
            method.setAccessible(true);
            if (method.getReturnType().equals(String.class)){
                String result = (String) method.invoke(ghostClass.newInstance());
                concat += result;
            }
        }
        return concat;
    }

    public String findSecretId(List<Secret> sl, String email) throws Exception{
        for (Secret secret : sl) {
            if (secret.isThis(email)) {
                Field uniqueId = secret.getClass().getDeclaredField("uniqueId");
                uniqueId.setAccessible(true);
                return (String) uniqueId.get(secret);
            }
        }
        return "NaN";
    }
}