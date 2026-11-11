Under the hood TS always get's converted into JS as it can't run as it is.
That's why in production JS is what is being run so that's why we need runtime validation in Production as it can't check the type of user request without that.
We can use Zod/other library or mannual JS validation for this.