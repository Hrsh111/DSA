# Data Lakes vs Data Warehouses

## Comparison
| Feature | Data Lake | Data Warehouse |
|---------|-----------|---------------|
| Data Type | Raw, unstructured/structured | Processed, structured |
| Schema | Schema-on-read | Schema-on-write |
| Users | Data scientists, engineers | Business analysts |
| Processing | ELT (Extract, Load, Transform) | ETL (Extract, Transform, Load) |
| Cost | Cheap (object storage) | Expensive (compute-optimized) |
| Query Speed | Slower (raw data) | Fast (pre-processed, indexed) |
| Examples | S3 + Athena, HDFS | Snowflake, BigQuery, Redshift |

## Key Points
- **Data Lake**: Dump everything in raw form, figure out structure later. Flexible but can become a "data swamp."
- **Data Warehouse**: Clean, structured data ready for business queries. Fast but rigid schema.
- **Data Lakehouse**: Combines both — raw storage with a structured layer on top (Delta Lake, Apache Iceberg)
- Modern trend: Lakehouse architecture is becoming standard

## When to Use
- **Data Lake**: ML training data, raw logs, exploratory analysis
- **Data Warehouse**: Business dashboards, reports, KPIs, SQL analytics

## Interview Tips
- "Raw events go to the data lake (S3), ETL pipeline processes them into the data warehouse (Redshift) for analytics"
- Mention the lakehouse trend if asked about modern data architecture

## Best Articles
- [Data Lake vs Warehouse - Databricks](https://www.databricks.com/discover/data-lakes/introduction)
- [Data Lakehouse Architecture](https://www.databricks.com/glossary/data-lakehouse)
