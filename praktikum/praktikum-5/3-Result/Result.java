public class Result<T, E extends Exception> implements IResult<T, E> {
    private T data;
    private E error;
  
    // return new Result object with data based on input
    public static <T, E extends Exception> Result<T, E> ok(T data) {
        Result<T, E> result = new Result<>();
        result.data = data;

        return result;
    }
  
    // return new Result object with error based on input
    public static <T, E extends Exception> Result<T, E> err(E error) {
        Result<T, E> result = new Result<>();
        result.error = error;

        return result;
    }
  
    // implement all other functions in the interface
    
    // returns true if the result data is not null
    public boolean isOk(){
        return data != null;
    }

    // returns true if the result Err is not null
    public boolean isErr(){
        return error != null;
    }

    // returns the data if the result is Ok, otherwise throws the error
    public T unwrap() throws Exception{
        if(isOk()){
            return data;
        } else{
            throw error;
        }
    }

    // returns the data if the result is Ok, otherwise returns the default value
    public T unwrapOrElse(T defaultValue){
        if(isOk()){
            return data;
        } else{
            return defaultValue;
        }
    }

    // returns the data if the result is Ok, otherwise throws the default exception
    public T unwrapOrThrow(Exception defaultException) throws Exception{
        if(isOk()){
            return data;
        } else{
            throw defaultException;
        }
    }
  }