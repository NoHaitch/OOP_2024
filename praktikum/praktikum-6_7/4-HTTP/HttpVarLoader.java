import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.HashMap;

public class HttpVarLoader {

    private HashMap<String, String> headers;
    private HashMap<String, String> body;
    private HashMap<String, String> query;
    private HashMap<String, String> cookie;

    /**
     * Variabel HTTP direpresentasikan dengan HashMap key-value.
     * Asumsikan:
     * - Tidak mungkin ada key berupa null
     * - Value mungkin null
     * 
     * @param headers
     * @param body
     * @param query
     * @param cookie
     */
    public HttpVarLoader(HashMap<String, String> headers, HashMap<String, String> body, HashMap<String, String> query,
                         HashMap<String, String> cookie) {
        this.headers = new HashMap<>(headers);
        this.body = new HashMap<>(body);
        this.query = new HashMap<>(query);
        this.cookie = new HashMap<>(cookie);
    }

    /**
     * Melakukan load variabel HTTP terhadap objek pada atribut dan method yang
     * menggunakan annotation HttpVar
     * 
     * @param obj Objek
     * @throws NullPointerException      Jika parameter obj bernilai null, atau jika
     *                                   nama variabel yang diminta tidak ada pada
     *                                   daftar variabel HTTP. Throw exception ini
     *                                   tanpa string message apapun.
     * @throws InvocationTargetException Jika method yang dipanggil meng-throw
     *                                   exception. Perhatikan bahwa Method.invoke()
     *                                   meng-throw exception ini.
     */
    public void load(Object obj) throws NullPointerException, InvocationTargetException {
        if (obj == null) {
            throw new NullPointerException();
        }

        Class<?> clazz = obj.getClass();
        Field[] fields = clazz.getDeclaredFields();
        Method[] methods = clazz.getDeclaredMethods();

        // Process fields
        for (Field field : fields) {
            if (field.isAnnotationPresent(HttpVar.class)) {
                HttpVar httpVar = field.getAnnotation(HttpVar.class);
                String value = getValue(httpVar.type(), httpVar.name());
                if (value == null) {
                    throw new NullPointerException();
                }
                field.setAccessible(true);
                try {
                    field.set(obj, value);
                } catch (IllegalAccessException e) {
                    e.printStackTrace();
                }
            }
        }

        // Process methods
        for (Method method : methods) {
            if (method.isAnnotationPresent(HttpVar.class)) {
                HttpVar httpVar = method.getAnnotation(HttpVar.class);
                String value = getValue(httpVar.type(), httpVar.name());
                if (value == null) {
                    throw new NullPointerException();
                }
                if (method.getParameterCount() == 1 && method.getParameterTypes()[0] == String.class) {
                    method.setAccessible(true);
                    try {
                        method.invoke(obj, value);
                    } catch (IllegalAccessException e) {
                        e.printStackTrace();
                    }
                }
            }
        }
    }

    private String getValue(HttpVar.Type type, String name) {
        switch (type) {
            case Query:
                return query.get(name);
            case Header:
                return headers.get(name);
            case Cookie:
                return cookie.get(name);
            case Body:
                return body.get(name);
            default:
                return null;
        }
    }
}
