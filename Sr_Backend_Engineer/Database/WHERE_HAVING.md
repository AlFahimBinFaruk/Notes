# SQL Server: WHERE, GROUP BY, HAVING, and COUNT()

A short reference using `dbo.RegistrationLogFCPS1`.

## 1. Example table

| RegistrationId | EnrollerId | Eligibility |
|---|---|---|
| 1 | 101 | 1 |
| 2 | 101 | 1 |
| 3 | 102 | 1 |
| 4 | 102 | 0 |
| 5 | NULL | 1 |

## 2. WHERE filters rows

```sql
SELECT *
FROM dbo.RegistrationLogFCPS1
WHERE Eligibility = 1;
```

Returns registrations **1, 2, 3, and 5**. `WHERE` can match any number of rows; it isn't restricted to one record.

## 3. COUNT(*) vs COUNT(column)

```sql
SELECT
    COUNT(*) AS AllEligibleRows,
    COUNT(EnrollerId) AS EligibleRowsWithEnroller,
    COUNT(DISTINCT EnrollerId) AS UniqueEnrollers
FROM dbo.RegistrationLogFCPS1
WHERE Eligibility = 1;
```

| AllEligibleRows | EligibleRowsWithEnroller | UniqueEnrollers |
|---:|---:|---:|
| 4 | 3 | 2 |

- `COUNT(*)`: counts **all matching rows**, including rows with `NULL` values.
- `COUNT(EnrollerId)`: counts matching rows where `EnrollerId` is **not NULL**; duplicates still count.
- `COUNT(DISTINCT EnrollerId)`: counts **different non-NULL** enroller IDs.

## 4. GROUP BY makes a group for each enroller

```sql
SELECT EnrollerId, COUNT(*) AS TotalRegistrations
FROM dbo.RegistrationLogFCPS1
GROUP BY EnrollerId;
```

| EnrollerId | TotalRegistrations |
|---|---:|
| 101 | 2 |
| 102 | 2 |
| NULL | 1 |

Each distinct `EnrollerId` value forms a group (including one group for `NULL`).

## 5. HAVING filters groups by aggregate results

Find enrollers with **more than one eligible registration**:

```sql
SELECT EnrollerId, COUNT(*) AS TotalRegistrations
FROM dbo.RegistrationLogFCPS1
WHERE Eligibility = 1
GROUP BY EnrollerId
HAVING COUNT(*) > 1;
```

**Result:** `EnrollerId = 101`, `TotalRegistrations = 2`.

Logical order: `FROM` → `WHERE` (eligible rows) → `GROUP BY` (per enroller) → `HAVING` (groups with count > 1) → `SELECT` (display).

## 6. HAVING without GROUP BY

You can check a total count across **all filtered rows** without separating them by enroller:

```sql
SELECT COUNT(*) AS TotalRecords
FROM dbo.RegistrationLogFCPS1
WHERE Eligibility = 1
HAVING COUNT(*) >= 3;
```

Here, the eligible count is **4**, so the query returns **4**. If the count were below 3, it would return **no rows** (not zero).

`HAVING` also **does not require** `COUNT(*)` in `SELECT`:

```sql
SELECT 'Enough registrations' AS Result
FROM dbo.RegistrationLogFCPS1
WHERE Eligibility = 1
HAVING COUNT(*) >= 3;
```

Returns one row containing `Enough registrations`. `'Enough registrations'` is a **string literal**; `Result` is the output **column alias**.

Without `GROUP BY`, the qualifying rows form **one implicit group**, so you can't also select an unaggregated `EnrollerId` directly:

```sql
-- INVALID: which EnrollerId from the single aggregate group?
SELECT EnrollerId, COUNT(*)
FROM dbo.RegistrationLogFCPS1
HAVING COUNT(*) > 1;
```

Use `GROUP BY EnrollerId` if you want counts per enroller.

## Quick mental map

- **WHERE** = *Which rows qualify?*
- **GROUP BY** = *Which rows belong together?*
- **COUNT(*)** = *How many rows?*
- **COUNT(column)** = *How many non-NULL values in this column?*
- **HAVING** = *Which aggregated groups qualify?*
- **SELECT** = *What should the result display?*

## Microsoft references

- [COUNT (Transact-SQL)](https://learn.microsoft.com/en-us/sql/t-sql/functions/count-transact-sql?view=sql-server-ver17)
- [HAVING (Transact-SQL)](https://learn.microsoft.com/en-us/sql/t-sql/queries/select-having-transact-sql?view=sql-server-ver17)
