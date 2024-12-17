import spacy

# Load the spaCy model
nlp = spacy.load("en_core_web_sm")

# Example text
text = " Fiserv.Newton.Diagnostics.Log4NetSink [TenantConfigurationProvider-Redis] InitializeSettingGroups Error:System.AggregateException: One or more errors occurred. ---> StackExchange.Redis.RedisConnectionException: No connection is available to service this operation: HGETALL Configuration:metadata; Error: NOAUTH Authentication required. Verify if the Redis password provided is correct.; IOCP: (Busy=0,Free=1000,Min=2,Max=1000), WORKER: (Busy=1,Free=32766,Min=2,Max=32767), Local-CPU: n/a ---> StackExchange.Redis.RedisConnectionException: AuthenticationFailure on WatServer1.pqa.net:6379/Subscription, origin: SetResult, input-buffer: 102, outstanding: 1, last-read: 0s ago, last-write: 0s ago, unanswered-write: -944538s ago, keep-alive: 60s, pending: 0, state: ConnectedEstablishing, last-heartbeat: never, last-mbeat: -1s ago, global: 0s ago, mgr: ProcessReadQueue, err: never ---> System.Exception: Error: NOAUTH Authentication required. Verify if the Redis password provided is correct.."

# Process the text
doc = nlp(text)

# Extract named entities
for entity in doc.ents:
    print(f"Entity: {entity.text}, Label: {entity.label_}")
